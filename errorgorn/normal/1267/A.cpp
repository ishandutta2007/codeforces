#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
int n;
vector<ii> swords_in;
vector<ii> swords_out;
vector<ii> first;
multiset<ll> len;
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    ll a,b,c;

    for (int x=0;x<n;x++){
        scanf("%lld%lld%lld",&a,&b,&c);
        b-=c;
        swords_in.push_back(ii(a,c));
        swords_out.push_back(ii(b,c));
        first.push_back(ii(a,a+c));
    }

    sort(swords_in.begin(),swords_in.end());
    sort(swords_out.begin(),swords_out.end());
    sort(first.begin(),first.end(),[](ii i,ii j){
        return i.second<j.second;
    });

    reverse(swords_in.begin(),swords_in.end());
    reverse(swords_out.begin(),swords_out.end());
    reverse(first.begin(),first.end());

    ll curr=swords_in.back().first;
    ll next;
    ll small;
    ll ans=0;
    ll extra;
    ll prev=-1; ///this is to not make it TLE.

    while (!swords_in.empty() && swords_in.back().first<=curr){
        //printf("adding sword of size %lld to the set\n",swords_in.back().second);
        len.insert(swords_in.back().second);
        swords_in.pop_back();
    }
    while (!swords_out.empty()){
        if (curr==prev) return 1;
        //printf("%lld %lld\n",prev,curr);
        prev=curr;
        //printf("now processing: %lld, curr swords: %lld\n",curr,ans);

        if (swords_in.empty()) next=swords_out.back().first;
        else{
            next=min(swords_in.back().first,swords_out.back().first);
        }

        if (!len.empty()) small=*len.begin();
        else{
            curr=next;
            goto _rebuild;
        }

        //printf("next: %lld\n",next);
        extra=(next-curr)/small;

        //printf("adding: %lld swords of size %lld\n",extra,small);
        ans+=extra;
        curr+=extra*small;

        while (!first.empty() && first.back().first<curr){
            first.pop_back();
        }

        if (!first.empty() && curr+small>first.back().second){
           //printf("adding: one of size %lld\n",first.back().second-first.back().first);
           ans++;
           curr=first.back().second;
        }
        else{
            //printf("adding: one of size %lld\n",small);
            ans++;
            curr+=small;
        }
        _rebuild:
        while (!swords_in.empty() && swords_in.back().first<=curr){
            //printf("adding sword of size %lld to the set\n",swords_in.back().second);
            len.insert(swords_in.back().second);
            swords_in.pop_back();
        }
        while (!swords_out.empty() && swords_out.back().first<curr){
            //printf("removing sword if length %d\n",swords_out.back().second);
            len.erase(len.find(swords_out.back().second));
            swords_out.pop_back();
        }
    }

    printf("%lld\n",ans);
}