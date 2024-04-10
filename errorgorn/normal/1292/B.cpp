#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<long long,long long> ii;

vector<ii> v;

long long dist(ii i,ii j){
    return abs(i.first-j.first)+abs(i.second-j.second);
}

int test(long long r,long long c,long long time,int start){
    time-=dist(ii(r,c),v[start]);
    
    if (time<0) return 0;
    
    int res=1;
    
    r=v[start].first,c=v[start].second;
    
    for (int x=start-1;~x;x--){
        time-=dist(v[x+1],v[x]);
        if (time<0) return res;
        res++;
    }
    
    for (int x=start+1;;x++){
        time-=dist(v[x-1],v[x])*2;
        if (time<0) return res;
        res++;
    }
}

int main(){
    long long x0,y0,ax,ay,bx,by;
    
    cin>>x0>>y0>>ax>>ay>>bx>>by;
    
    v.push_back(ii(x0,y0));
    
    while (max(v.back().first,v.back().second)<30000000000000000){
        v.push_back(ii(v.back().first*ax+bx,v.back().second*ay+by));
    }
    long long X,Y,T;
    cin>>X>>Y>>T;
    
    int ans=0;
    for (int x=0;x<v.size();x++){
        ans=max(ans,test(X,Y,T,x));
    }
    
    reverse(v.begin(),v.end());
    for (int x=0;x<v.size();x++){
        ans=max(ans,test(X,Y,T,x));
    }
    
    cout<<ans;
}