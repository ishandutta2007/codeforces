#include<bits/stdc++.h>

using namespace std;
const int MAXN = 2e5;
const int MAXL = 2e6;

int N;
long long L[MAXN];

long long go() {
vector<long long> lens;
while(N >= 2) {
if(L[N - 1] - L[N - 2] > 1) N --;
else lens.push_back(L[N - 2]), N -= 2;
}
long long res = 0;
for(int i = 0; 2 * i + 1 < lens.size(); i++) {
res += lens[2 * i] * lens[2 * i + 1];
}
return res;
}

int main() {
cin >> N;
for(int i = 0; i < N; i++) cin >> L[i];
sort(L, L + N);
cout << go() << '\n';
return 0;
}