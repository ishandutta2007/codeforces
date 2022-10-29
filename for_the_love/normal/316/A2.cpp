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
int cnt[1005];
string s;
int main(){
    while (cin >> s){
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < s.size(); i++) cnt[s[i]]++;
        int num = 0;
        for (int i = 'A'; i <= 'J'; i++)
        if (cnt[i]) num++;
        int ans = 1;
        for (int i = 0; i < num; i++) ans *= 10 - i;
        if (s[0] >= 'A' && s[0] <= 'J'){
            int t = 1;
            for (int i = 1; i < num; i++) t *= 10 - i;
            ans -= t;
        }else if (s[0] == '?'){
            cnt['?']--; ans *= 9;
        }
        printf("%d", ans);
        for (int i = 0; i < cnt['?']; i++) printf("0");
        puts("");
    }
}