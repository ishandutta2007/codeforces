#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int N, vis[200];
vector<pair<int,int> > andrew;
void dfs(int c) {
if(!vis[c]){
vis[c] = true;
for(int n = 0; n < andrew.size(); n++){
int a = andrew[c].first, b = andrew[c].second, e = andrew[n].first, d = andrew[n].second;
if((e < a && a < d) || (e < b && b < d)){
dfs(n);}}}}
int query (int a, int b){
memset(vis, 0, sizeof(vis));
dfs(a);
return vis[b];}

main(){
cin >> N;
for(int i = 0; i < N; i++){
int v, a, b; cin >> v >> a >> b;
if(v == 1){
andrew.push_back(make_pair(a, b));}
else if(v == 2){
cout << (query(a - 1, b - 1) ? "YES" : "NO") << '\n';}}return 0;}