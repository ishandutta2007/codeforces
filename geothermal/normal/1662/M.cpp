#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n,m;
        cin >> n >> m;
        int maxr = 0;
        int maxw = 0;
        for (int i = 1;i <= m;i++){
            int r,w;
            cin >> r >> w;
            maxr = max(r,maxr);
            maxw = max(w,maxw);
        }
        if (maxr+maxw > n){
            cout << "IMPOSSIBLE\n";
        }
        else{
            for (int i = 1;i <= maxr;i++) cout << 'R';
            for (int i = maxr+1;i <= n;i++) cout << 'W';
            cout << endl;
        }
    }
}