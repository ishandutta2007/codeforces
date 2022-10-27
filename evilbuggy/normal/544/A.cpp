#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k;
    cin>>k;
    string q;
    cin>>q;
    int a[26] = {0};
    vector<int> arr;
    int i, j;
    for(i = 0, j = 0; i < q.size() && j < k; i++){
        if(a[q[i] - 'a'] == 0){
            arr.push_back(i);
            a[q[i] - 'a']++;
            j++;
        }
    }
    if(j != k){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        for(int i = 1; i < k; i++){
            for(int j = arr[i-1]; j < arr[i]; j++){
                cout<<q[j];
            }
            cout<<endl;
        }
        for(int i = arr.back(); i < q.size(); i++){
            cout<<q[i];
        }
        cout<<endl;
    }
}