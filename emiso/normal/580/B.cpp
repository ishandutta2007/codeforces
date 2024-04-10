#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n,d,m,f,left,right;

vector<pair<int,int> > amigo;

long long ans,sum;

inline long long llmax(long long a, long long b) {
    return a>b?a:b;
}

int main() {
    scanf("%d %d",&n,&d);
    for(int i=0;i<n;i++) {
        scanf("%d %d",&m,&f);
        amigo.push_back(make_pair(m,f));
    }
    sort(amigo.begin(),amigo.end());

    for(int i=0;i<n;i++) {
        sum += (1LL * amigo[i].second);

        while(amigo[i].first - amigo[left].first >= d) {
            sum -= amigo[left].second;
            left++;
        }

        ans = llmax(ans,sum);
    }

    printf("%I64d\n",ans);
    return 0;
}