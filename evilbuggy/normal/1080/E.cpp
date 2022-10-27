#include <bits/stdc++.h>

using namespace std;

string s[255];
int mask[255], cnt[255][26];
int len[255];
int n,m;

bool isPal(int i){
    int x = mask[i], tmp = 0;
    while(x > 0){
        tmp += x%2;
        x >>= 1;
    }
    return tmp < 2;
}

bool equal(int i, int j){
    if(mask[i] != mask[j])return false;
    if(!isPal(i))return false;
    for(int k = 0; k < 26; k++){
        if(cnt[i][k] != cnt[j][k])return false;
    }
    return true;
}

int compute(){
    int l = 0, r = -1;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(!isPal(i))len[i] = 0;
        else{
            int k = (i > r)?1:min(len[l+r-i], r-i);
            while(0 <= i - k && i + k < n && equal(i-k, i+k)){
                k++;
            }
            len[i] = k--;
            if(i + k > r){
                l = i - k;
                r = i + k;
            }
        }
        ans += len[i];
    }
    l = 0, r = -1;
    for(int i = 0; i < n; i++){
        if(!isPal(i))len[i] = 0;
        else{
            int k = (i > r)?0:min(len[l+r-i+1], r-i+1);
            while (0 <= i-k-1 && i + k < n && equal(i-k-1, i+k)){
                k++;
            }
            len[i] = k--;
            if (i + k > r) {
                l = i - k - 1;
                r = i + k ;
            }
        }
        ans += len[i];
    }
    return ans;
}


int main(){
    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    for(int i = 0; i < n; i++){
        cin>>s[i];
    }
    long long int ans = 0;
    for(int cs = 0; cs < m; cs++){
        //Odd length;
        for(int i = 0; i < n; i++){
            mask[i] = 0;
            for(int j = 0; j < 26; j++){
                cnt[i][j] = 0;
            }
        }
        for(int ce = cs; ce < m; ce++){
            for(int i = 0; i < n; i++){
                mask[i] ^= (1<<(s[i][ce]-'a'));
                cnt[i][s[i][ce] - 'a']++;
                //cout<<cs<<" "<<ce<<" "<<i<<" "<<mask[i]<<" "<<cnt[i][0]<<" "<<cnt[i][2]<<endl;
            }
            
            ans += compute();

        }
    }
    cout<<ans<<endl;
}