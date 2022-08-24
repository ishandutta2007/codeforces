#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

const int N = 120;
char ban[N][N];

int main(){

    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (a[i][j] == 'o'){
                for (int x = 0; x < n; x++){
                    for (int y = 0; y < n; y++){
                        if (a[x][y] == '.'){
                            ban[x - i + n][y - j + n] = 1;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (a[i][j] == 'x'){
                bool ok = false;
                for (int x = 0; x < n; x++){
                    for (int y = 0; y < n; y++){
                        if (a[x][y] == 'o' && !ban[i - x + n][j - y + n])
                            ok = true;
                    }
                }
                if (!ok){
                    puts("NO");
                    return 0;
                }
            }
        }
    }
    puts("YES");
    for (int i = -n + 1; i <= n - 1; i++){
        for (int j = -n + 1; j <= n - 1; j++){
            if (i == 0 && j == 0)
                cout << "o";
            else {
                if (ban[i + n][j + n])
                    cout << ".";
                else
                    cout << "x";
            }
        }
        cout << "\n";
    }

    return 0;
}