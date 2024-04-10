#include <iostream>
#include <algorithm>

using namespace std;

int a[110];

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        for (int i = 1;i <= 10;i++){
            a[i] = -1;
        }
        for (int i = 1;i <= n;i++){
            int b,d;
            cin >> b >> d;
            a[d] = max(a[d],b);
        }
        bool tf = true;
        int ans = 0;
        for (int i = 1;i <= 10;i++){
            if (a[i] == -1){
                tf = false;
                break;
            }
            ans += a[i];
        }
        if (!tf){
            cout << "MOREPROBLEMS\n";
        }
        else{
            cout << ans << endl;
        }
    }
}