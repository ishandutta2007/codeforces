#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
long long n;
int f1,f2,f3,c;
const long long MOD=1000000007,MOD2=1000000006;
struct matrix_exp{
    int s;
    vector<vector<long long> > pow;
    vector<vector<long long> > mat;
    vector<long long> empty_vector;
    long long mod;
    long long exp;
    matrix_exp(int _s,vector<vector<long long> > _mat, long long _exp, long long _mod){
        s=_s;
        for (int x=0;x<s;x++){
            pow.push_back(empty_vector);
            mat.push_back(empty_vector);
            for (int y=0;y<s;y++){
                pow[x].push_back(_mat[x][y]);
                mat[x].push_back(_mat[x][y]);
            }
        }
        mod=_mod;
        exp=_exp;
    }
    void mul(){
        long long arr[s][s];
        long long k;
        for (int x=0;x<s;x++){
            for (int y=0;y<s;y++){
                k=0;
                for (int z=0;z<s;z++){
                    k+=mat[x][z]*pow[z][y];
                    k%=mod;
                }
                arr[x][y]=k;
            }
        }
        for (int x=0;x<s;x++){
            for (int y=0;y<s;y++){
                mat[x][y]=arr[x][y];
            }
        }
    }
    void sq(){
        long long arr[s][s];
        long long k;
        for (int x=0;x<s;x++){
            for (int y=0;y<s;y++){
                k=0;
                for (int z=0;z<s;z++){
                    k+=mat[x][z]*mat[z][y];
                    k%=mod;
                }
                arr[x][y]=k;
            }
        }
        for (int x=0;x<s;x++){
            for (int y=0;y<s;y++){
                mat[x][y]=arr[x][y];
            }
        }
    }
    vector<vector<long long> > query(){
        stack<int> s;
        while (exp){
            if (exp&1){
                s.push(1);
                exp--;
            }
            else {
                s.push(0);
                exp>>=1;
            }
        }
        s.pop();
        while (!s.empty()){
            if (s.top()){
                mul();
            }
            else{
                sq();
            }
            s.pop();
        }
        return mat;
    }
};
struct int_exp{
    long long base;
    long long exp;
    long long mod;
    int_exp(long long _base, long long _exp, long long _mod){
        base=_base;
        exp=_exp;
        mod=_mod;
    }
    int query(){
        stack<int> s;
        while (exp){
            if (exp&1){
                s.push(1);
                exp--;
            }
            else {
                s.push(0);
                exp>>=1;
            }
        }
        long long ans=1;
        while (!s.empty()){
            if (s.top()){
                ans*=base;
            }
            else{
                ans*=ans;
            }
            ans%=mod;
            s.pop();
        }
        return ans;
    }
};
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%lld%d%d%d%d",&n,&f1,&f2,&f3,&c);
    vector< vector<long long> > mat={ {1,1,1}, {1,0,0}, {0,1,0} };
    matrix_exp *root;
    root=new matrix_exp(3,mat,n-3,MOD2);
    mat=root->query();
    /*for (int x=0;x<3;x++){
        for (int y=0;y<3;y++){
            printf("%d ",mat[x][y]);
        }
        printf("\n");
    }*/
    long long ans=1;
    int_exp *root2;
    root2=new int_exp(f1,mat[0][2],MOD);
    ans*=root2->query();
    ans%=MOD;
    root2=new int_exp(f2,mat[0][1],MOD);
    ans*=root2->query();
    ans%=MOD;
    root2=new int_exp(f3,mat[0][0],MOD);
    ans*=root2->query();
    ans%=MOD;
    mat={ {1,1,1,2,MOD2-4}, {1,0,0,0,0}, {0,1,0,0,0}, {0,0,0,1,1}, {0,0,0,0,1} };
    root=new matrix_exp(5,mat,n-3,MOD2);
    mat=root->query();
    root2=new int_exp(c,(mat[0][3]*3+mat[0][4])%MOD2,MOD);
    ans*=root2->query();
    //printf("%d\n",(mat[0][3]*3+mat[0][4])%MOD2);
    ans%=MOD;
    printf("%lld\n",ans);
}