#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
//tesing the effectiveness of __gnu_pbds::priority_queue
//to see if it's worth using
//probably should try an alternate dijkstra implementation later
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef tuple<ll,int,int>plii;
 
const int MAXN=3000005;
 
vector<plii>v[MAXN];
bool bio[MAXN];
 
int main(){
 
ios_base::sync_with_stdio(false);
cin.tie(0);
 
int n,m,k;
cin>>n>>m>>k;
for(int i=0;i<m;i++){
int a,b,w;
cin>>a>>b>>w;
a--,b--;
v[a].emplace_back(-w,b,i+1);
v[b].emplace_back(-w,a,i+1);
}
std::priority_queue<plii>pq;
pq.push(make_tuple(0,0,0));
vector<int>rj;
while(!pq.empty()&&rj.size()<k){
int node,e;ll w;
tie(w,node,e)=pq.top();
pq.pop();
if(bio[node])continue;
if(e)rj.push_back(e);
bio[node]=1;
for(plii x : v[node]){
ll nw;int nn,ne;
tie(nw,nn,ne)=x;
pq.push(make_tuple(nw+w,nn,ne));
}
}
cout<<rj.size()<<"\n";
for(auto x : rj)cout<<x<<" ";
}