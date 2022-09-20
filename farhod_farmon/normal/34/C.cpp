#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;
const int Q = 1000010;

using namespace std;

string s;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> s;
        vector < int > v;
        int x = 0;
        s += ",";
        for(int i = 0; i < s.size(); i++){
                if(s[i] == ','){
                        v.push_back(x);
                        x = 0;
                } else{
                        x = x * 10 + s[i] - '0';
                }
        }

        sort(v.begin(), v.end());
        vector < int > nv;
        for(int i = 0; i < v.size(); i++){
                if(i > 0 && v[i] == v[i - 1]){
                        continue;
                }
                nv.push_back(v[i]);
        }
        v = nv;

        for(int i = 0; i < v.size();){
                int j = i;
                while(j + 1 < v.size() && v[j + 1] == v[j] + 1){
                        j += 1;
                }
                if(i == j){
                        cout << v[i];
                } else{
                        cout << v[i] << "-" << v[j];
                }
                i = j + 1;
                if(i != v.size()){
                        cout << ",";
                }
        }
}