#include <bits/stdc++.h>

#define fi first
#define se second
#define pt pair < double, double >

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                int last = -1;
                for(int i = 0; i < n; i++){
                        char x;
                        cin >> x;
                        for(int j = 1; j >= 0; j--){
                                if(x - '0' + j != last){
                                        last = x - '0' + j;
                                        break;
                                }
                        }
                        cout << last - (x - '0');
                }
                cout << "\n";
        }
}