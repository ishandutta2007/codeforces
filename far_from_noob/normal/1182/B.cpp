#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define dd double
#define fo(i,n) for(int i=0;i<n;i++)
//vector<int>v[200005];

using namespace std;
ll n,t,m,k,x,y;

int main()
{
    t=1;
    //cin>>t;
    while(t--){
        cin>>n>>m;
        char a[n][m];
        int count=0,c1=0,c2=0,c3=0,c4=0,temp=1;
        fo(i,n){
        fo(j,m){cin>>a[i][j];
        if(a[i][j]=='*')count++;
        }
        }
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(a[i][j]=='*'){
                    while(a[i][j+temp]=='*'){c1++;temp++; if(j+temp==m)break;}
                    temp=1;
                    while(a[i][j-temp]=='*'){c2++;temp++;if(j-temp==-1)break;}
                    temp=1;
                    while(a[i+temp][j]=='*'){c3++;temp++;if(i+temp==n)break;}
                    temp=1;
                    while(a[i-temp][j]=='*'){c4++;temp++;if(i-temp==-1)break;}
                    temp=1;
                    if(c1+c2+c3+c4+1==count && c1>0&&c2>0 &&c3>0 &&c4>0){cout<<"YES";return 0;}
                    if((c1>0||c2>0)&&(c3>0||c4>0)){cout<<"NO";return 0;}
                    c1=0;c2=0;c3=0;c4=0;               }
            }
        }
        cout<<"NO";

    }
    return 0;
}