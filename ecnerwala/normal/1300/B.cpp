#include<bits/stdc++.h>
using namespace std;
int main() { int T; scanf("%d",&T); while (T--) {
int N; scanf("%d",&N);
vector<int> A(2*N); for (int&a:A) scanf("%d",&a);
auto b=begin(A);
nth_element(b,b+N,end(A));
printf("%d\n",A[N]-*max_element(b,b+N));
}}