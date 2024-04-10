#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n;
long long k;
vector<int> original,s;
long long num[100005];
void print(){
    for (int x=0;x<s.size();x++){
        printf("%d %d\n",s[x],num[x]);
    }
    printf("\n");
}
int main(){
    scanf("%d%lld",&n,&k);
    int t;
    for (int x=0;x<n;x++){
        scanf("%d",&t);
        original.push_back(t);
    }
    sort(original.begin(),original.end());
    s.push_back(original[0]);
    num[0]=1;
    int iter=0;
    for (vector<int>::iterator it=++original.begin();it!=original.end();it++){
        if (s.back()==*it){
            num[iter]++;
        }
        else{
            s.push_back(*it);
            num[++iter]++;
        }
    }
    int fit=0,bit=s.size()-1;
    long long diff=s.back()-s[0];
    int delta;
    while (diff){
        if (num[fit]<num[bit]){
            delta=s[fit+1]-s[fit];
            if (k>=delta*num[fit]){
                k-=delta*num[fit];
                diff-=delta;
                num[fit+1]+=num[fit];
                fit++;
            }
            else{
                diff-=k/num[fit];
                break;
            }
        }
        else{
            delta=s[bit]-s[bit-1];
            if (k>=delta*num[bit]){
                k-=delta*num[bit];
                diff-=delta;
                num[bit-1]+=num[bit];
                bit--;
            }
            else{
                diff-=k/num[bit];
                break;
            }
        }
    }
    printf("%lld\n",diff);
}