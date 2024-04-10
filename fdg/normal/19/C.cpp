#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Interv{
    Interv(int f,int m1) : f(f), m1(m1) {};
    int f,m1;
    int size()
    {
        return m1-f;
    }
};

bool operator <(Interv a,Interv b)
{
    if (a.size()<b.size()) return true;
    if (a.size()==b.size()&&a.f<b.f) return true;
    return false;
}

int main()
{
    map <int,int> nums;
    vector < vector <int> > v;
    int n,k=0,a,num,mas[100001]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        mas[i]=a;
        if (nums.count(a)==0) 
        {
            nums[a]=k++;
            v.push_back(vector <int>());
        }
        v[nums[a]].push_back(i);
    }
    int left=0;
    vector <Interv> it;
    for(int i=0;i<k;i++)
    {
        sort(v[i].begin(),v[i].end());
        for(int j=0;j<v[i].size();j++)
            for(int t=j+1;t<v[i].size();t++)
                it.push_back(Interv(v[i][j],v[i][t]));
    }
    sort(it.begin(),it.end());
    for(int i=0;i<it.size();i++)
    {
        if (it[i].f<left) continue;
        bool correct=true;
        for(int j=1;j<it[i].size();j++)
        {
            if (i+j>=it.size()||it[i+j].f!=it[i+j-1].f+1)
            {
                correct=false;
                break;
            }
        }
        if (correct) left=it[i].m1,i+=it[i].m1-it[i].f-1;
    }
    printf("%d\n",n-left);
    for(int i=left;i<n;i++)
        if (i==left) printf("%d",mas[i]);
        else printf(" %d",mas[i]);
    printf("\n");
    return 0;
}