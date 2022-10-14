/**
 *    author:  gary
 *    created: 01.07.2022 21:55:35
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
int a[505],b[505];
void solve(){
    int n;
    cin>>n;
    rb(i,1,n) cin>>a[i];
    a[0]=a[n+1]=INF;
    rb(i,1,n) cin>>b[i];
    map<mp,int> A,B;
    rb(i,1,n-1) A[II(min(a[i],a[i+1]),max(a[i],a[i+1]))]++,B[II(min(b[i],b[i+1]),max(b[i],b[i+1]))]++;
    if(A!=B||a[1]!=b[1]||a[n]!=b[n]) cout<<"NO\n";
    else{
        cout<<"YES\n";
        vector<mp> ope;
        rb(i,1,n){
            if(a[i]!=b[i]){
                rb(j,i+1,n){
                    if(a[j]==b[i]&&(a[j-1]==a[i-1]||a[j+1]==a[i-1])){
                        // cout<<j<<"___\n";
                        if(a[j+1]==a[i-1]&&j!=n){
                            ope.PB(II(i-1,j+1));
                            reverse(a+i-1,a+j+1+1);
                        }
                        else{
                            bool ok=0;
                            rb(k,j+1,n){
                                if(a[k]==a[i-1]){
                                    ope.PB(II(j-1,k));
                                    reverse(a+j-1,a+k+1);
                                    ope.PB(II(i-1,k));
                                    reverse(a+i-1,a+k+1);
                                    ok=1;
                                    break;
                                }
                            }
                            if(!ok){
                                rb(l,i,j-2)
                                rb(z,j,n) if(a[l]==a[z]){
                                    ope.PB(II(l,z));
                                    reverse(a+l,a+z+1);
                                    rb(j,i+1,n){
                                        if(a[j]==b[i]&&(a[j-1]==a[i-1]||a[j+1]==a[i-1])){
                                            // cout<<j<<"___\n";
                                            if(a[j+1]==a[i-1]){
                                                ope.PB(II(i-1,j+1));
                                                reverse(a+i-1,a+j+1+1);
                                            }
                                            else{
                                                bool ok=0;
                                                rb(k,j+1,n){
                                                    if(a[k]==a[i-1]){
                                                        ope.PB(II(j-1,k));
                                                        reverse(a+j-1,a+k+1);
                                                        ope.PB(II(i-1,k));
                                                        reverse(a+i-1,a+k+1);
                                                        ok=1;
                                                        break;
                                                    }
                                                }
                                                if(!ok){
                                                    rb(l,i,j-2)
                                                    rb(z,j,n) if(a[l]==a[z]){
                                                        ope.PB(II(l,z));
                                                        reverse(a+l,a+z+1);
                                                        
                                                    }
                                                    break;
                                                }
                                            }
                                            break;
                                        }
                                    }
                                    break;
                                }
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        }
        cout<<ope.size()<<endl;
        for(auto it:ope) cout<<it.first<<" "<<it.second<<endl;
        rb(i,1,n) {
            assert(a[i]==b[i]);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}