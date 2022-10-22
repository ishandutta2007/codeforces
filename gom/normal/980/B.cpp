#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,t,kk;
int a[5][100];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;kk=k;
    if(k&&k%2){
        a[2][(n+1)/2]=1;
        t++;
    }
    else if(k){
        a[2][(n+1)/2]=a[3][(n+1)/2]=1;
        t+=2;
    }
    for(int d=1;t<k;d++){
            if(t+4<=k){
                a[2][(n+1)/2-d]=a[3][(n+1)/2-d]=a[2][(n+1)/2+d]=a[3][(n+1)/2+d]=1;
                t+=4;
            }
            else{
                a[2][(n+1)/2-d]=a[2][(n+1)/2+d]=1;
                t+=2;
            }
    }/*
    if(t>kk){
        a[2][(n+1)/2-k/2]=a[2][(n+1)/2+k/2]=0;
    }
    cout<<t<<endl;*/
    cout<<"YES\n";
    for(int i=1;i<=4;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==0)
                cout<<'.';
            else
                cout<<'#';
        }
        cout<<'\n';
    }
    return 0;
}