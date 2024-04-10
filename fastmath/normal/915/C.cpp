#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;
#define int long long

const int MOD = 1e9 + 7;

bool check(vector <int> a, vector <int> b){
    if ((int)a.size() == 0 && (int)b.size() == 0) return true;

    sort(a.begin(), a.end());
    if (a[0] < b[0]) return true;
    if (b[0] < a[0]) return false;
    
    vector <int> a1, b1;
    for (int i = 1; i < a.size(); ++i){
        a1.push_back(a[i]);
        b1.push_back(b[i]);
    }

    return check(a1, b1);
}

bool comp(int a, int b){
    return a > b;
}

signed main(){
    ios_base::sync_with_stdio(false);
    
    string s, t;
    cin >> s >> t;

    vector <int> a, b;
    for (int i = 0; i < s.size(); ++i){
        a.push_back(s[i] - '0');
    }

    for (int i = 0; i < t.size(); ++i){
        b.push_back(t[i] - '0');
    }

    if (a.size() < b.size()){
        sort(a.begin(), a.end(), comp);
        for (int elem: a){
            cout << elem;
        }
        return 0;
    }

    vector <int> ans;
    bool win = false;
    while (a.size()){
        sort(a.begin(), a.end(), comp);

        if (a[0] < b[0]){
            win = true;
            ans.push_back(a[0]);
            a.erase(a.begin());
            b.erase(b.begin());
            continue;
        }

        vector <int> a1, b1;
        bool get = false;
        int getpos = -1;
        for (int i = 0; i < a.size(); ++i){
            if (a[i] != b[0]) {
                a1.push_back(a[i]);
            }
            else{
                if (!get){
                     get = true;
                     getpos = i;
                }
                else{
                     a1.push_back(a[i]);
                }   
            }

            if (i) b1.push_back(b[i]);
        }

        if (win){
            ans.push_back(a[0]);
            a.erase(a.begin());
            b.erase(b.begin());
        }
        else if (get && check(a1, b1)){
            ans.push_back(b[0]);
            a.erase(a.begin() + getpos);
            b.erase(b.begin());
        }
        else{
            win = true;
            for (int i = 0; i < a.size(); ++i){
                if (a[i] < b[0]){
                    ans.push_back(a[i]);
                    a.erase(a.begin() + i);
                    break;
                }
            }
            b.erase(b.begin());
        }
    }

    for (int elem: ans){
        cout << elem;
    }

    return 0;
}