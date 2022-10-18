#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <ctime>
#include <set>
#pragma comment(linker, "/STACK:65777216")

#define ll long long

using namespace std;

struct op{
    int k,f[5],s[5];
};

int nums[100005]={0},n;
vector <op> ret;
vector <op> tmp[6];

int spos=-1;
vector < pair<int,int> > tops;
bool ok[100005]={0};

void dfs(int pos)
{
    if (pos==spos&&tops.size()>0)
    {
        op no;
        no.k=tops.size();
        for(int i=0;i<tops.size();i++)
        {
            no.s[(i+no.k-1)%no.k]=no.f[i]=tops[i].second+1;
//          no.f[i]=tops[i].second+1;
            ok[tops[i].first]=true;
        }
//      sort(tops.begin(),tops.end());
//      for(int i=0;i<tops.size();i++)
//          no.s[i]=tops[i].second+1;
        ret.push_back(no);
        tops.clear();
        spos=-1;
        return;
    }
    if (tops.size()==5)
    {
        op no;
        no.k=5;
        for(int i=0;i<tops.size();i++)
        {
            if (i<4) ok[tops[i].first]=true;
            no.s[(i+no.k-1)%no.k]=no.f[i]=tops[i].second+1;
        }
        ret.push_back(no);
        nums[spos]=tops[4].first;
        tops.clear();
        return;
    }
    tops.push_back(make_pair(nums[pos],pos));
    dfs(nums[pos]);
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&nums[i]);
        nums[i]--;
    }
    ret.clear();
    for(int i=0;i<n;i++)
        if (nums[i]==i) ok[i]=true;
    for(int i=0;i<n;i++)
        if (!ok[nums[i]])
        {
            spos=i;
            while(spos!=-1)
                dfs(spos);
        }
    for(int i=0;i<ret.size();i++)
    {
        tmp[ret[i].k].push_back(ret[i]);
    }
    ret.clear();
    for(int i=0;i<tmp[5].size();i++)
        ret.push_back(tmp[5][i]);
    for(int i=0;i<tmp[4].size();i++)
        ret.push_back(tmp[4][i]);
    while(tmp[3].size()>tmp[2].size()+1)
    {
        int ind=tmp[3].size()-1;
        op no1;
        no1.k=2;
        no1.f[0]=tmp[3][ind].f[0];
        no1.f[1]=tmp[3][ind].f[1];
        no1.s[0]=tmp[3][ind].s[0];
        no1.s[1]=tmp[3][ind].s[2];
        op no2;
        no2.k=2;
        no2.f[0]=tmp[3][ind].f[0];
        no2.f[1]=tmp[3][ind].f[2];
        no2.s[0]=tmp[3][ind].s[1];
        no2.s[1]=tmp[3][ind].s[2];
        tmp[2].push_back(no1);
        tmp[2].push_back(no2);
        tmp[3].pop_back();
    }
    int c3=0,c2=0;
    while(c2<tmp[2].size()&&c3<tmp[3].size())
    {
        tmp[3][c3].k=5;
        tmp[3][c3].f[3]=tmp[2][c2].f[0];
        tmp[3][c3].f[4]=tmp[2][c2].f[1];
        tmp[3][c3].s[3]=tmp[2][c2].s[0];
        tmp[3][c3].s[4]=tmp[2][c2].s[1];
        ret.push_back(tmp[3][c3]);
        c2++; c3++;
    }
    while(c3<tmp[3].size())
    {
        ret.push_back(tmp[3][c3]);
        c3++;
    }
    while(c2<tmp[2].size())
    {
        if (c2+1<tmp[2].size())
        {
            tmp[2][c2].k=4;
            tmp[2][c2].f[2]=tmp[2][c2+1].f[0];
            tmp[2][c2].f[3]=tmp[2][c2+1].f[1];
            tmp[2][c2].s[2]=tmp[2][c2+1].s[0];
            tmp[2][c2].s[3]=tmp[2][c2+1].s[1];
            ret.push_back(tmp[2][c2]);
            c2+=2;
        }
        else
        {
            ret.push_back(tmp[2][c2]);
            c2++;
        }
    }
    cout << ret.size() << endl;
    for(int i=0;i<ret.size();i++)
    {
        printf("%d\n",ret[i].k);
        printf("%d",ret[i].f[0]);
        for(int j=1;j<ret[i].k;j++)
            printf(" %d",ret[i].f[j]);
        printf("\n");
        printf("%d",ret[i].s[0]);
        for(int j=1;j<ret[i].k;j++)
            printf(" %d",ret[i].s[j]);
        printf("\n");
    }
/*  srand(clock());
    vector <int> vv;
    for(int j=0;j<30;j++)
        vv.push_back(j+1);
    random_shuffle(vv.begin(),vv.end());
    cout << vv.size() << endl;
    for(int i=0;i<vv.size();i++)
        cout << vv[i] << " ";
    cout << endl;
*/  return 0;
}