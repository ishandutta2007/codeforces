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

int n;
int a[100007];
map<int, int> was;


int main(){
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int uk = 0;
    for (int i = 0; i < n; i++){
        if (a[i] > uk) cout << i + 1, exit(0);
        was[a[i]] = 1;
        while(was[uk]) uk++;
    }
    cout << -1;
}