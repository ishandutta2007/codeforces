#include <bits/stdc++.h>
#define in long long
#define fo(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    in n,m,k;
    cin>>n>>m>>k;
    in a[n];
    fo(i,n)cin>>a[i];
    in l[m],r[m],d[m];
    fo(i,m)cin>>l[i]>>r[i]>>d[i];
    in x[k],y[k];
    fo(i,k)cin>>x[i]>>y[i];
    in p[m];
    fo(i,m)p[i]=0;
    fo(i,k){
        p[x[i]-1]++;
        p[y[i]]--;
    }
    for(in i=1;i<m;i++)p[i]+=p[i-1];
    in v[n];
    fo(i,n)v[i]=0;
    fo(i,m){
        v[l[i]-1]+=p[i]*d[i];
        v[r[i]]-=p[i]*d[i];
    }
    for(in i=1;i<n;i++)v[i]+=v[i-1];
    fo(i,n)cout<<a[i]+v[i]<<" ";
    //cout << "Hello world!" << endl;
    return 0;
}