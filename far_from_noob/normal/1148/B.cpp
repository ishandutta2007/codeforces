#include <iostream>
#include<bits/stdc++.h>
# define fo(i,n) for(int i=0;i < (n);i++)
#define ll long long
using namespace std;
 vector<int>v[2005];
//void maxheight(int hmax,vector<int>v[],)

int main()
{
    int n,m,ta,tb,k;
    cin>>n>>m>>ta>>tb>>k;
    int a[n],a1[n];
    int b[m];
    //if(k>=n || k>=m){cout<<-1;return 0;}
    fo(i,n)cin>>a[i];
    fo(i,m){cin>>b[i];}
    if(k>=n || k>=m){cout<<-1;return 0;}

    fo(i,n){a1[i]=a[i]+ta;}
    int c[n+m];
    fo(i,n)c[i]=a1[i];
    fo(i,m)c[n+i]=b[i];
    sort(c,c+n+m);
    int flag1=0,flag2=0,flagi=0,temp=0,tempb=0;
    int next[k+1];
    for(int i=0;i<k+1;i++){
        if(a1[i]<=b[temp]){
            next[i]=temp;
        }
        else {temp++;
        i--;
        }
        if(temp>=m){cout << -1;return 0;}
    }
    if(next[0]+k>=m){cout<<-1;return 0;}
    //cout<<next[0]<<next[1]<<next[2];
    int ans[k+1];
    for(int i=0;i<=k;i++){
        if(i==0)ans[i]=b[k+ next[0]];
        else {
            if(k - i + next[i]  >= m ){cout<<-1;return 0;}
            ans[i]= b[k - i + next[i]];
        }
        }
    sort(ans,ans+k+1);
    cout<<ans[k]+tb;


    return 0;
}