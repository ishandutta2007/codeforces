#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;

bool is(char a[], int n){
    for (int i=0; i<n; ++i){
	if (a[i] != a[n-1-i]) return false;
    }
    return true;
}

char a[10000];

bool gao(){
    int n, k;
    cin >> a;
    cin >> k;
    n = strlen(a);
    if (n % k != 0) return false;
    for (int i=0; i<n; i+=n/k){
	if (!is(a+i, n/k)) return false;
    }
    return true;
}

int main(){
    if (gao()){
	puts("YES");
    }else{
	puts("NO");
    }
    return 0;
}