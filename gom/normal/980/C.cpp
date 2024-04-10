#include <bits/stdc++.h>
#define N 100005
using namespace std;
typedef long long ll;
int n,k,cs=0,p[N],color[300];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        p[i]++;
        if(color[p[i]])
            continue;
        int s=-1;
        for(int j=p[i]-1;j>=1;j--){
            if(color[j]){
                s=j;
                break;
            }
        }
        if(s==-1){
            for(int j=max(1,p[i]-k+1);j<=p[i];j++){
                color[j]=max(1,p[i]-k+1);
            }
            continue;
        }
        int ss=color[s];
        if(ss+k-1>=p[i]){
            for(int j=s+1;j<=p[i];j++)
                color[j]=ss;
            continue;
        }
        int nc=max({1,s+1,p[i]-k+1});
        for(int j=nc;j<=p[i];j++)
            color[j]=nc;
    }
    for(int i=1;i<=n;i++)
        cout<<color[p[i]]-1<<" ";
    return 0;
}