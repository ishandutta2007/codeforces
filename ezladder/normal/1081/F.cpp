#include <bits/stdc++.h>
                  
using namespace std;
          
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n, k;

int a[333];
int b[333];

int sd[11] = {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1};

int ask(int l, int r){
    int ans = 0;
    if (rand() % 1 == 0){
        for (int i = 1; i <= r; i++){
            sd[i] ^= 1;
        }
    } else {
        for (int i = l; i <= n; i++){
            sd[i] ^= 1;
        }
    }
    for (int i = 1; i <= n; i++) ans += sd[i];
    return ans;
}

int getlast(){
    int d = 0;
    while(1){
        cout << "? 1 " << n - 1 << endl;
        int ans;
        cin >> ans;
        //ans = ask(1, n - 1);
        if (ans == n - k){
            for (int j = 1; j <= n; j++) a[j] ^= 1, b[j] ^= 1;
            k = ans;
            d ^= 1;
        } else {
            int need = k;
            for (int j = 1; j <= n - 1; j++) a[j] ^= 1, b[j] ^= 1;
            int re;
            if (ans == n - k + 1) re = 1; else re = 0;
            k = ans;
            re ^= d;
            //cout << "AAA " << re << endl;
            return re;
        }   
    }
}

int getlast2(){
    while(1){
        cout << "? 1 " << n - 1 << endl;
        int ans;
        cin >> ans;
        //ans = ask(1, n - 1);
        if (ans == n - k){
            for (int j = 1; j <= n; j++) a[j] ^= 1, b[j] ^= 1;
            k = ans;
        } else {
            int need = k;
            for (int j = 1; j <= n - 1; j++) a[j] ^= 1, b[j] ^= 1;
            int re;
            if (ans == n - k + 1) re = 1; else re = 0;
            k = ans;
            //cout << "AAA " << re << endl;
            return re;
        }   
    }
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    //ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    //n = 10;
    //k = 5;

    if (n == 1){
        cout << "! " << k << endl;
        exit(0);
    }

    b[n] = getlast2();
    for (int i = n - 1; i >= 2; i--){
        while(1){
            //for (int s = 1; s <= n; s++) cout << a[s];
            //    cout << endl;
            //for (int s = 1; s <= n; s++) cout << b[s];
            //    cout << endl;
            cout << "? 1 " << i - 1 << endl;
            int ans;
            cin >> ans;
            //ans = ask(1, i - 1);
            int save = ans;
            int need = k;
            int lol = b[n];
            //cout << "wtf" << need << ' ' << ans << endl;
            for (int j = i + 1; j <= n; j++) need -= b[j], ans -= b[j];

            int kek;
            //cout << "---" << ans << endl;
            if (ans == i - need + 1) kek = 1; else kek = 0;
            k = save;

            b[i] = kek;
            //cout << "====" << lol << ' ' << "===" << kek << endl;
            int now = getlast();
            //cout << "====" << now << endl;
            if (now == lol){
                for (int j = 1; j <= i - 1; j++) a[j] ^= 1, b[j] ^= 1;
                //cout << "============" << (b[i] ^ a[i]) << endl;
                break;
            } else {
                for (int j = 1; j <= n; j++) a[j] ^= 1, b[j] ^= 1;
            }
        }
    }
    //cout << "sfddsf " << k << ' ' << a[1] << ' ' << b[2] << ' ' << b[3] << endl;
    for (int i = 2; i <= n; i++) k -= b[i];
    b[1] = k;

    cout << "! ";
    for (int i = 1; i <= n; i++){
        cout << (a[i] ^ b[i]);
    }
    cout << endl;
}