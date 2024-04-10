#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#pragma comment(linker, "/STACK:65777216")

#define ll long long

using namespace std;

// 0 - W
// 1 - HBox
// 2 - VBox

ll sp[101]={0},bor[101]={0},cnt=0,type[101],W[101],H[101],par[101]={0};
map <string,int> f;
vector <int> in[101];
ll rw[101]={0},rh[101]={0};

void calc(int i)
{
    if (rw[i]!=-1) return;
    if (type[i]==0)
    {
        rw[i]=W[i]; rh[i]=H[i];
        return;
    }
    if (type[i]==1)
    {
        ll ww=0,hh=0;
        for(int t=0;t<in[i].size();t++)
        {
            if (t!=0) ww+=sp[i];
            calc(in[i][t]);
            hh=max(hh,rh[in[i][t]]);
            ww+=rw[in[i][t]];
        }
        rw[i]=ww+2*bor[i]; rh[i]=hh+2*bor[i];
        if (in[i].size()==0) rw[i]=rh[i]=0;
    }
    if (type[i]==2)
    {
        ll ww=0,hh=0;
        for(int t=0;t<in[i].size();t++)
        {
            if (t!=0) hh+=sp[i];
            calc(in[i][t]);
            ww=max(ww,rw[in[i][t]]);
            hh+=rh[in[i][t]];
        }
        rw[i]=ww+2*bor[i]; rh[i]=hh+2*bor[i];
        if (in[i].size()==0) rw[i]=rh[i]=0;
    }
}


int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int q;
    scanf("%d\n",&q);
    char mas[1001]={0};
    for(int i=0;i<q;i++) par[i]=-1;
    for(int i=0;i<q;i++)
    {
        gets(mas);
        int l=strlen(mas);
        if (l>8&&mas[0]=='W'&&mas[6]==' ')
        {
            char name[11]={0},a;
            istringstream ss(mas);
            ss >> name;
            int nl=0;
            while(ss>>a)
            {
                if (a=='(') break;
                name[nl++]=a;
            }
            name[nl]='\0';
            int w,h;
            ss >> w >> a >> h >> a;
            type[cnt]=0; W[cnt]=w; H[cnt]=h;
            f[name]=cnt; cnt++;
        }
        else
        {
            if (l>5&&mas[4]==' ')
            {
                if (mas[0]=='H')
                {
                    char name[11]={0};
                    istringstream ss(mas);
                    ss >> name >> name;
                    type[cnt]=1;
                    f[name]=cnt; cnt++;
                }
                else
                {
                    char name[11]={0};
                    istringstream ss(mas);
                    ss >> name >> name;
                    type[cnt]=2;
                    f[name]=cnt; cnt++;
                }
            }
            else
            {
                istringstream ss(mas);
                char name[11]={0},a;
                int nl=0;
                while(ss >> a)
                {
                    if (a=='.') break;
                    name[nl++]=a;
                }
                name[nl]='\0';
                ss >> a;
                if (a=='p')
                {
                    ss >> a >> a >> a >> a;
                    char sname[11]={0},c=0;
                    while(ss >> a)
                    {
                        if (a==')') break;
                        sname[c++]=a;
                    }
                    sname[c]='\0';
                    in[f[name]].push_back(f[sname]);
                }
                else
                {
                    ss >> a >> a >> a >> a;
                    if (a=='b')
                    {
                        ss >> a >> a >> a >> a >> a >> a;
                        int b=0; ss >> b;
                        bor[f[name]]=b;
                    }
                    else
                    {
                        ss >> a >> a >> a >> a >> a >> a >> a;
                        int b=0; ss >> b;
                        sp[f[name]]=b;
                    }
                }
            }
        }
    }
    map <string,pair <ll,ll> > ans;
    for(int i=0;i<cnt;i++) rw[i]=-1;
    for(map <string,int>::iterator it=f.begin();it!=f.end();it++)
    {
        int num=it->second;
        if (rw[num]==-1) calc(num);
        ans[it->first]=make_pair(rw[num],rh[num]);
    }
    for(map <string,pair <ll,ll> >::iterator it=ans.begin();it!=ans.end();it++)
        cout << (*it).first << " " << (*it).second.first << " " << (*it).second.second << endl;
    return 0;
}