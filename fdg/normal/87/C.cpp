#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define ll long long

using namespace std;

int xor[100001]={0};
int ret[100001]={0};

int solve(int n)
{
    if (xor[n]!=-1) return xor[n];
    vector <int> v;
    for(int k=2;k*(k+1)/2<=n;++k)
    {
        int a=n-k*(k+1)/2;
        if (a%k!=0) continue;
        a=1+a/k;
        int cur=0;
        for(int j=a;j<a+k;j++)
        {
            solve(j);
            cur^=xor[j];
        }
        if (cur==0&&ret[n]==-1) ret[n]=k;
        v.push_back(cur);
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    int res=0;
    for(int i=0;i<v.size();i++)
        if (v[i]==res) res++;
        else break;
    xor[n]=res;
    return ret[n];
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<=n;i++) ret[i]=xor[i]=-1;
    printf("%d\n",solve(n));
    return 0;
}