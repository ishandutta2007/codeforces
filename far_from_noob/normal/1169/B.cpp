#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#define fo(i,n) for(int (i) = 0 ; i < (n) ; i++)
#define ll long long
#define do double
int main() {
    int n,m;
    cin>>n>>m;
    if(m<=2)cout<<"YES";
    else{
    pair<int,int> a[m];
    map<int ,int>count;
    fo(i,m){cin>>a[i].first>>a[i].second;
        count[a[i].first]++;
        if(a[i].first!=a[i].second)count[a[i].second]++;
    }
    //cout<<count[2]<<count[1];
    int f[4],fvalue[4],temp=0;
    for(int i=0;i<m;i++){
        if(count[a[i].first]>=m/2){
            fvalue[temp]=count[a[i].first];
           count[a[i].first]=0;
           //cout<<a[i].first;
           f[temp]=a[i].first;
           temp++;
        }
        if(count[a[i].second]>=m/2){
            fvalue[temp]=count[a[i].second];
           count[a[i].second]=0;

           f[temp]=a[i].second;
           temp++;
        }
    }
    //cout<<count[2]<<count[4]<<count[1];
    int flag2=0;
    //cout<<fvalue[0];
    for(int j=0;j<temp;j++){
        if(fvalue[j]==m){flag2=1;break;}
        int flag=0,p,x=-1,y=-1;
        for( p=0;p<m;p++){
            if(a[p].first!=f[j] &&a[p].second!=f[j]){
                    x=a[p].first;
                    y=a[p].second;
                    break;
            }
        }
        map<int,int>recount;
        for(int i=p;i<m;i++){
            if(a[i].first!=f[j] &&a[i].second!=f[j] ){
                    recount[a[i].first]++;
                    recount[a[i].second]++;
            }
        }
        if(recount[x]==m-fvalue[j]|| recount[y]==m-fvalue[j]){
            flag2=1;
            break;
        }

    }
    if(flag2)cout<<"YES";
    else cout<<"NO";
    }
    return 0;
}