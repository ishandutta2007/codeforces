#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

string s;
int a[1000];
int main(){
    cin >> s;
    int now = 0, cnt = 0;
    for (int i = 0; i < s.size(); i++)
    if (s[i] == '+'){
        a[++cnt] = now;
        now = 0;
    }else now = now * 10 + s[i] - '0';
    a[++cnt] = now;
    sort(a + 1, a + cnt + 1);
    for (int i = 1; i < cnt; i++) printf("%d+", a[i]); printf("%d\n", a[cnt]);
}