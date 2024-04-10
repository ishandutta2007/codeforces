#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define ll long long

int main(){
ll n, ans = 0;
queue <int> q1, q2;
cin >> n;
int t; cin >> t;
for (int i =0 ; i < t; i++){
int t1; cin >> t1; q1.push(t1);
}
cin >> t;
for (int i =0 ; i < t; i++){
int t1; cin >> t1; q2.push(t1);
}
int i = 0;
while (!q1.empty() && !q2.empty() && i < 5 * 1e7){
i++;
if (q1.front() > q2.front()){
q1.push(q2.front());
q1.push(q1.front());
q1.pop();
q2.pop();
} else {
q2.push(q1.front());
q2.push(q2.front());
q1.pop();
q2.pop();
}
}
if (!q1.empty() && !q2.empty()) cout << -1;
else if (!q1.empty()) cout << i << " " << 1;
else cout << i << " " << 2;
}