#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 100000;

map<string, pair<int,int> > arr;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    int n;
    cin>>n;
    arr["void"] = {0,0};
    arr["errtype"] = {-inf, -inf};
    string a, b, c, d;
    while(n--){
        cin>>c>>a;
        if(c == "typedef"){
            cin>>b;
            int ac = 0, sc = 0;
            int i = 0;
            d = "";
            for(; i < a.size(); i++){
                if(a[i] == '&')ac++;
                else if(a[i] == '*')sc++;
                else d = d + a[i];
            }
            if(arr.find(d) == arr.end()){
                arr[b] = {-inf, -inf};
                continue;
            }
            pair<int,int> tmp = arr[d];
            tmp = {tmp.first + ac, tmp.second + sc};
            if(tmp.first < 0 || tmp.second < 0 || tmp.first > tmp.second){
                tmp = {-inf, -inf};
            }
            arr[b] = tmp;
            // cout<<d<<" "<<arr[d].first<<" "<<arr[d].second<<endl;
        }else{
            int ac = 0, sc = 0;
            int i = 0;
            d = "";
            for(; i < a.size(); i++){
                if(a[i] == '&')ac++;
                else if(a[i] == '*')sc++;
                else d = d + a[i];
            }
            pair<int,int> tmp = {-inf, -inf};
            if(arr.find(d) != arr.end()){
                tmp = arr[d];
            }
            tmp = {tmp.first + ac, tmp.second + sc};
            if(tmp.first < 0 || tmp.second < 0 || tmp.first > tmp.second){
                cout<<"errtype"<<endl;
            }else{
                int cnt = tmp.second - tmp.first;
                cout<<"void";
                while(cnt--){
                    cout<<'*';
                }
                // cout<<tmp.first<<" "<<tmp.second;
                cout<<endl;
            }
        }
    }
}