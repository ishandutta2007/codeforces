#include<bits/stdc++.h>
#define maxn 234560

using namespace std;
int n;
char s[maxn];

int main(){
    cin >> n >> s;
    int cnt=0;
    for (int i=0;i<n;i++) cnt+=(s[i]=='8');
    cout << min(n/11,cnt) << endl;
}