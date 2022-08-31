#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
    int x;
    scanf("%d", &x);
    return x;
}

int main(){

    string s[8];
    for (int i = 0; i < 8; i++)
        cin >> s[i];
    int a = INT_MAX;
    for (int i = 0; i < 8; i++){
        int j = 0;
        while (j < 8 && s[j][i] != 'W'){
            if (s[j][i] == 'B')
                j = INT_MAX;
            else
                j++;
        }
        if (j < 8)
            a = min(a, j);
    }
    int b = INT_MAX;
    for (int i = 0; i < 8; i++){
        int j = 7;
        while (j >= 0 && s[j][i] != 'B'){
            if (s[j][i] == 'W')
                j = INT_MIN;
            else
                j--;
        }
        if (j > 0)
            b = min(b, 7 - j);
    }

    puts(a <= b ? "A" : "B");

    return 0;
}