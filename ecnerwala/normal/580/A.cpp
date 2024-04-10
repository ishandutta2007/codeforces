#include<bits/stdc++.h>
using namespace std;

int main (){
int n; cin >> n;
int res = 0;
int cnt = 0;
int p = 0;
while(n--){
int a; cin >> a;
if(a >= p) cnt ++;
else cnt = 1;
res = max(res, cnt);
p=a;
}
cout << res << '\n';
}