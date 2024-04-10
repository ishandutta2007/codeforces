#include <stdio.h>
#include <algorithm>
#define ATK 0
#define DEF 1

using namespace std;

int n, m;
char str[5];
int strength[2][105];
bool pos[105];
pair<int, int> card[105];
int def_cards[105], def_cardN=0, atk_cards[105], atk_cardN=0;
bool used[105];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=0; i < n; ++i){
        scanf("%s%d", str, strength[0]+i);
        if(str[0] == 'A'){
            pos[i]=ATK;
            atk_cards[atk_cardN++]=strength[0][i];
        }
        else{
            pos[i]=DEF;
            def_cards[def_cardN++]=strength[0][i];
        }
        card[i]=make_pair(strength[0][i], pos[i]);
    }
    for(int i=0; i < m; ++i){
        scanf("%d", strength[1]+i);
    }
    sort(card, card+n);
    sort(strength[1], strength[1]+m);
    sort(atk_cards, atk_cards+atk_cardN);
    sort(def_cards, def_cards+def_cardN);
    int ans1=0, ans2=0;
    int ans=0;
    //Destroy All
    bool ok=1;
    for(int i=0; i < m; ++i){
        used[i]=0;
    }
    for(int i=0; i < def_cardN; ++i){
        ok=0;
        for(int j=0; j < m; ++j){
            if(strength[1][j] > def_cards[i] && !used[j]){
                used[j]=true;
                ok=1;
                break;
            }
        }
        if(!ok)
            break;
    }
    if(ok){
        for(int i=0; i < atk_cardN; ++i){
            ok=0;
            for(int j=0; j < m; ++j){
                if(strength[1][j] >= atk_cards[i] && !used[j]){
                    used[j]=true;
                    ok=1;
                    ans1 += strength[1][j] - atk_cards[i];
                    break;
                }
            }
            if(!ok)
                break;
        }
        for(int i=0; i < m; ++i){
            if(!used[i])
                ans1 += strength[1][i];
        }
        if(ok)
            ans=ans1;
    }
    for(int i=0; i < m; ++i){
        used[i]=0;
    }
    for(int i=0; i < atk_cardN; ++i){
        for(int j=m-1; j >= 0; --j){
            if(strength[1][j] >= atk_cards[i] && !used[j]){
                used[j]=true;
                ans2 += strength[1][j] - atk_cards[i];
                break;
            }
        }
    }
    if(ans2 > ans)
        ans=ans2;
    printf("%d\n", ans);
    return 0;
}