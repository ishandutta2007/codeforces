#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, pone[100005], ptwo[100005];

int search(int ll, int k){
    int ind1 = -1, ind2 = -1;
    int l = ll, r = n;
    while(l < r){
        int m = l + (r - l)/2;
        if(pone[m] - pone[ll-1] >= k){
            r = m;
        }else{
            l = m + 1;
        }
    }
    if(pone[l] - pone[ll - 1] == k)ind1 = l;
    l = ll, r = n;
    while(l < r){
        int m = l + (r - l)/2;
        if(ptwo[m] - ptwo[ll-1] >= k){
            r = m;
        }else{
            l = m + 1;
        }
    }
    if(ptwo[l] - ptwo[ll - 1] == k)ind2 = l;
    if(ind1 == -1)return ind2;
    if(ind2 == -1)return ind1;
    return min(ind1, ind2);
}

int count(int k){
    int cnt1 = 0, cnt2 = 0, pre = -1;
    for(int r, l = 1; l <= n; l = r + 1){
        r = search(l, k);
        // cout<<k<<" "<<l<<" "<<r<<endl;
        if(r == -1)return -1;
        if(pone[r] - pone[l-1] == k){
            cnt1++;
            pre = 1;
        }else if(ptwo[r] - ptwo[l-1] == k){
            cnt2++;
            pre = 2;
        }else return -1;
    }
    if(pre == 2 && cnt2 > cnt1)return cnt2;
    if(pre == 1 && cnt1 > cnt2)return cnt1;
    return -1;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);
    cin>>n;
    pone[0] = ptwo[0] = 0;

    int x;
    for(int i = 1; i <= n; i++){
        cin>>x;
        pone[i] = pone[i-1];
        ptwo[i] = ptwo[i-1];
        if(x == 1)pone[i]++;
        else ptwo[i]++;
    }
    vector<pair<int,int> > arr;
    for(int k = 1; k <= n; k++){
        int tmp = count(k);
        if(tmp != -1){
            arr.push_back({tmp, k});
        }
    }
    sort(arr.begin(), arr.end());
    cout<<arr.size()<<endl;
    for(auto x: arr){
        cout<<x.first<<" "<<x.second<<endl;
    }
}