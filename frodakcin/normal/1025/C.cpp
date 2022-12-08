#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 101000;

string s;
int N;

int main() {
    cin >> s;
    N = s.size();
    
    int ans = 1;
    
    int cl = 1, cls = 0;
    bool prev = s[0] == 'w';
    for(int i = 1;i < N;i++) {
        if((s[i] == 'w') xor prev) cl++;
        else cl = 1, cls = i;
        if(cl > ans) ans = cl;
        prev = s[i] == 'w';
    }
    for(int i = 0;i < cls;i++) {
        if((s[i] == 'w') xor prev) cl++;
        else break;
        if(cl > ans) ans = cl;
        prev = s[i] == 'w';
    }
    
    printf("%d\n", ans);
    
    return 0;
}