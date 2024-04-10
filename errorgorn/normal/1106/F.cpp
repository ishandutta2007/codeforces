#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;

vector<vector<long long> > mul(vector<vector<long long> > i, vector<vector<long long> > j,int m){
    vector<vector<long long> > res;
    for (int x=0;x<i.size();x++){
        res.push_back(vector<long long>());
        for (int y=0;y<i.size();y++){
            res[x].push_back(0);
            for (int z=0;z<i.size();z++){
                res[x][y]=(res[x][y]+i[x][z]*j[z][y])%m;
            }
        }
    }
    return res;
}

vector<vector<long long> > mexp(vector<vector<long long> > mat,long long p,int m){
    if (p==1) return mat;
    vector<vector<long long> > res=mexp(mat,p>>1,m);
    res=mul(res,res,m);
    if (p&1) res=mul(res,mat,m);
    return res;
}


long long qexp(int b,int p,int m){
    if (p==0) return 1;
    else if (p==1) return b;
    long long r=qexp(b,p>>1,m);
    r=(r*r)%m;
    if (p&1) r=(r*b)%m;
    return r;
}

long long inverse(long long a, long long m){
    long long m0 = m;
    long long y = 0, x = 1;

    if (m == 1)
      return 0;

    while (a > 1)
    {
        // q is quotient
        long long q = a / m;
        long long t = m;

        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
       x += m0;

    return x;
}



int bsgs(int a,int b,int m){
    ///rmb to copy qexp code for this
    int sqrtm=sqrt(m);
    unordered_map<int,int> table;
    long long curr=1;
    long long mul=qexp(a,m-2,m);
    for (int x=0;x<sqrtm;x++){
        table[b*curr%m]=x;
        ///assume m is prime to find inverse
        curr=(curr*mul)%m;
    }
    curr=1;
    mul=qexp(a,sqrtm,m);
    for (int x=0;x<m;x+=sqrtm){
        if (table.count(curr)){
            return x+table[curr];
        }
        curr=(curr*mul)%m;
    }
    
    return -1; 
    ///this should never trigger if a is trivial root
}

const int MOD=998244353;

int k;
int arr[105];
int n,m;

int main(){
    scanf("%d",&k);
    for (int x=0;x<k;x++) scanf("%d",&arr[x]);
    scanf("%d%d",&n,&m);
    
    vector<vector<long long> > mat;
    
    for (int x=0;x<k;x++){
        mat.push_back(vector<long long>());
        for (int y=0;y<k;y++) mat[x].push_back(0);
    }
    
    for (int x=0;x<k;x++) mat[0][x]=arr[x];
    for (int x=0;x<k-1;x++) mat[x+1][x]=1;
    
    mat=mexp(mat,n-k,MOD-1);
    int power=mat[0][0];
    
    
    int power2=bsgs(3,m,MOD);
    
    ///we are finding x, we have (power)x=power2 (mod MOD-1)
    int modulo=MOD-1;
    int common=__gcd(power,modulo);
    if (power2%common!=0){
        printf("-1\n");
        return 0;
    }
    power/=common,power2/=common,modulo/=common;
    
    power2=(power2*inverse(power,modulo))%modulo;
    
    printf("%lld\n",qexp(3,power2,MOD));
}