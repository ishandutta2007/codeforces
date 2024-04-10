#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

string a, b;
int i, cnt1, cnt2;
int main(){
    cin >> a >> b;
    for (i = 0; i < a.size(); i++) cnt1 += (a[i] == '1');
    for (i = 0; i < b.size(); i++) cnt2 += (b[i] == '1');
    if (cnt1 % 2) cnt1++;
    if (cnt1 >= cnt2) printf("YES"); else printf("NO");
}