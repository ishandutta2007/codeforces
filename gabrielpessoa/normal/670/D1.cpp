#include <bits/stdc++.h>
using namespace std;

long long needed[100005];
long long has[100005];
pair<long long, pair<long long, long long>> arr[100005];

int main() {
    long long n, k, curNeeded, curHas;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> needed[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> has[i];
        arr[i] = make_pair(has[i]/needed[i], make_pair(needed[i], has[i] % needed[i]));
    }
    sort(arr, arr+n);
    curNeeded = 0;
    curHas = 0;
    for(int i = 0; i < n; i++) {
        //printf("%d %d %d %d %d\n", i, arr[i].first, curHas, curNeeded, k);
        if((arr[i].first - curHas) * curNeeded > k) {
            break;
        }
        k += arr[i].second.second - (arr[i].first - curHas) * curNeeded;
        curHas = arr[i].first;
        curNeeded += arr[i].second.first;
    }
    cout << curHas + k/curNeeded << endl;
    return 0;
}