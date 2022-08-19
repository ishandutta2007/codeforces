#include<bits/stdc++.h>
using namespace std;

int main(){
int prv = 0;
int N; cin >> N;
int res = 0;
for(int i = 0; i < N; i++) {
int v; cin >> v;
if(v == 1 && prv == 0) res+=1;
if(v == 1) res ++;
prv = v;
}
if(res >= 1) res --;
cout << res << '\n';
}