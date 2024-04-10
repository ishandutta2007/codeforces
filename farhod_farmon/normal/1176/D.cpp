#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define LL long long


using namespace std;

const int N = 3002000;
const LL MOD = 1e9 + 7;


int d1[1001][1001],d2[200][200][2];
LL a[N],a1[N],a2[N],a3[N];
bool used[N];
LL  sum=0,k=0,t=1,cnt=1,c=0;


int foo( int x )
{
    for( int i=2; i * i <= x; i++ ){
        if( x % i == 0 )return false;
    }
    return true;
}


int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    map < int ,int > m,m1,m2;
    for( int i=1; i<=n*2; i++ ){
        cin>>a[i];
        m1[a[i]]++;
    }
    for( int i=2; i<=2750131; i++ ){
        if( foo(i) ){
            m[t] = i;
            t++;
            m2[i]++;
        }
    }
    sort(a + 1, a + 2 * n + 1);
    reverse(a + 1, a + 2 * n + 1);
    vector< int > v;
    for( int i=1; i<=n*2; i++ ){
        if( m2[a[i]] > 0 && a[i] < 200000 ){
            if( m1[m[a[i]]] > 0 && m1[a[i]] > 0 ){
                m1[m[a[i]]]--;
                m1[a[i]]--;
                v.pb(a[i]);
            }
        }
        else{
            for(int j = 2; j * j <= a[i]; j++){
                if(a[i] % j == 0){
                        k = a[i] / j;
                        break;
                }
            }
            if( m1[k] > 0 && m1[a[i]] > 0 ){
                v.pb(a[i]);
                m1[k]--;
                m1[a[i]]--;
            }
        }
    }
    for( auto x : v )cout<<x<<" ";
}