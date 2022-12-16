#include <bits/stdc++.h>
using namespace std;

typedef long double T;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ii, int> iii;
typedef pair<ll, ll> llll;
typedef pair<T, T> dd;
typedef pair<dd, int> ddi;

const int SIZE  = 5005;
const int MOD = 1E9+7;
const int DELTA = 1E5+2;
const double PI = atan(1)*4;
const double EPS = 1e-7;
const int INF = 0x3f3f3f3f;
const double INFF = 1e100;

int nova[30];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout << fixed << setprecision(13);
    string s;
    cin >> s;
    int n = s.size();
    int chanceTotal = 0;
    for(char l = 'a'; l <= 'z'; l++) {
        int chanceL = 0;
        for(int segLetra = 1; segLetra < n; segLetra++) {
            int chanceTemp = 0;
            memset(nova, 0, sizeof(nova));
            for(int i = 0; i < n; i++) {
                int j = (segLetra + i) % n;
                if(s[i] == l) nova[s[j]-'a']++;
            }
            for(int i = 0; i <= 'z' -'a'; i++) {
                if(nova[i] == 1) chanceTemp++;
            }
            chanceL = max(chanceTemp, chanceL);
        }
        //printf("Letras possiveis no %c = %d\n", l, chanceL);
        chanceTotal += chanceL;
    }
    cout << (1.0*chanceTotal)/n << '\n';
 	return 0;
}