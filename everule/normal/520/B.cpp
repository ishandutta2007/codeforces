#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
vector<int> edge[20007]; 
void init(){
    for(int i=0;i<20007;i++){
         if(i-1>0){
         edge[i].pb(i-1);
         }
         if(2*i<20007){
         edge[i].pb(2*i);
         }
    }
}
ll solve(){
    int n,m;
    cin>>n>>m;
    queue<pair<int,int>> tochk;
    bool found[20000]={0};
    tochk.push(mp(n,0));
    while(!tochk.empty()){
        if(tochk.front().first==m){
            return tochk.front().second;
        }
        for(int i=0;i<edge[tochk.front().first].size();i++){
            if(!found[edge[tochk.front().first][i]]){
                 tochk.push(mp(edge[tochk.front().first][i],tochk.front().second+1));
                 found[edge[tochk.front().first][i]]=1;
            }
        }
        tochk.pop();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	//cin >>t;
	t=1;
    srand(time(0));
    init();
	while(t--){
	    cout<<solve()<<"\n";//solving it correctly
	}
}