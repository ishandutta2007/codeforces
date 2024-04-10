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

    int n = nxt();
    string s, t;
    cin >> s >> t;
    if (t == "week"){
        if (n == 5 || n == 6)
            puts("53");
        else
            puts("52");
    } else {
        int qw[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int cnt = 0;
        for (itn i = 0; i < 12; i++){
            if (qw[i] >= n)
                cnt++;
        }
        printf("%d\n", cnt);
    }

    return 0;
}