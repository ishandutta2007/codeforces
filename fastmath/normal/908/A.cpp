#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:1000000000")
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <random>
#include <time.h>
#include <queue>
#include <fstream>

using namespace std;
typedef long long ll;
#define int long long

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 7;

bool f1(char c){
    return (c == '1' || c == '3' || c == '5' || c == '7' || c == '9');
}

bool f2(char c){
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
	//freopen("", "r", stdin);
    //freopen("", "w", stdout);
    string s;
    cin >> s;
    int ans = 0;
    for (char c: s){
        ans += (f1(c) || f2(c));
    }

    cout << ans;
    return 0;
}