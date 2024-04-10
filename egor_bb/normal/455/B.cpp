#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>


#define maxn 100005
#define ll long long 
#define pb push_back

using namespace std;

struct vert{
int win, lose;
vector <int> a;
vert(){
a.resize(26, 0); win=0, lose=1;
}
};

vector <vert> g;

void add (string s){
int cur = 0;
for (int i = 0; i< s.size(); i++){
int t = s[i] - 'a';
if (g[cur].a[t] != 0) cur = g[cur].a[t];
else {
g.resize(g.size()+1);
g[cur].a[t] = g.size()-1;
cur = g.size()-1;
}
}
}

void dfs (int v){
int t = 0;
for (int i = 0; i < 26; i++){
int to =g[v].a[i];
if (g[v].a[i]!=0){
if(t==0){
t++;
g[v].lose=0;
}
dfs(to);
g[v].win=g[v].win | !g[to].win;
g[v].lose=g[v].lose | !g[to].lose;
}
}
}

int main(){
int n, k;
string s;
g.resize(1);
cin >> n >> k;
for (int i = 0; i < n; i++){
cin >> s;
add(s);
}
dfs(0);

if((g[0].win && g[0].lose) ||(g[0].win && k&1)) cout << "First";
else cout << "Second";


}