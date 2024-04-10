#include <bits/stdc++.h>
//#pragma comment(linker, /STACK:36777216)
           
using namespace std;
           
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int main(){
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    cout << 0 << ' ' << 1 << endl;
    int vl = 0, vr = 1e9;
    string ans;
    cin >> ans;
    string save = ans;
    for (int it = 0; it < n - 1; it++){
        int vm = (vl + vr) >> 1;
        cout << vm << ' ' << 1 << endl;
        cout.flush();
        cin >> ans;
        if (ans == save) vl = vm;
        else vr = vm;
    }
    cout << vl << ' ' << 2 << ' ' << vr << ' ' << 0;
    cout.flush();
}