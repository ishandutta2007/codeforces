
#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define dd double
#define endl "\n"
#define fo(i,n) for(int i=0;i<n;i++)
ll n,k,t,m,q,flag=0,count=0;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //cin>>t;
    t=1;
    while(t--){
        cin>>n>>m;
        ll x=1,y=1,temp=0,i;
        //cout<<"1 1"<<endl;
        for( i=n-1;i>0;i=i-2){

            ll flag=0;
            for(int j=m;j>0;j--){

                cout<<x<<" " << m+1-j<<endl<<x+i<<" "<<j<<endl;
            }
            temp++;
            if(i>=2){x=temp+1;y=1;}
        }
        if(i==0 ){
            ll flag=0;
            cout<<x<<" "<<y<<endl;
            for(int l=m-1;l>0;l=l-1){
                if(flag%2==0)
                cout<<temp+1<<" "<<y+l<<endl,y=y+l;
                else cout<<temp+1<<" "<<y-l<<endl,y=y-l;
            flag++;
            }
            return 0;
        }




    }

    return 0;
}