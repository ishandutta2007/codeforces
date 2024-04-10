#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+7;
typedef long long ll;
char s[maxn];
int n,p;
int main(){
    cin >> n >> s;
    for (int i=0;i<n;i++){
        if (s[i]=='(') p++; else p--;
        if (p<-1) {puts("No");return 0;}
    }
    if (p) puts("No"); else puts("Yes");
}