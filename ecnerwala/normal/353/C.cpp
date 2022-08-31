#include<iostream>

using namespace std;

const int MAXN = 200000;
int N;
int A[MAXN];
char S[MAXN];
int go() {
int ans = 0;
int sum = 0;
for(int i = 0; i < N; i++) if(S[i] == '1') sum += A[i];
ans = sum;
for(int i = 0; i < N; i++) {
if(S[i] == '1') {
sum -= A[i];
if(sum > ans) ans = sum;
}
sum += A[i];
}
return ans;
}
int main(){
cin >> N;
for(int i = 0; i < N; i++) cin >> A[i];
cin >> S;
cout << go() << '\n';
}