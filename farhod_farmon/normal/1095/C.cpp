#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
int k;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> k;
        multiset < int > s;
        for(int i = 0; i < 31; i++){
                if(n & (1 << i)){
                        s.insert(1 << i);
                }
        }
        while(s.size() < k){
                int x = *(--s.end());
                s.erase(--s.end());
                if(x == 1){
                        break;
                }
                s.insert(x / 2);
                s.insert(x / 2);
        }
        if(s.size() != k){
                cout << "NO" << "\n";
                return 0;
        }
        cout << "YES" << "\n";
        while(!s.empty()){
                cout << *s.begin() << " ";
                s.erase(s.begin());
        }
}