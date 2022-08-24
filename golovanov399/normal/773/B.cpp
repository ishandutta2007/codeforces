#include <bits/stdc++.h>

using namespace std;

int score_mult(int a, int b)
{
    assert(a >= 0 && a <= b && b > 0);
    
    if (a * 2 > b) return 1;
    if (a * 4 > b) return 2;
    if (a * 8 > b) return 3;
    if (a * 16 > b) return 4;
    if (a * 32 > b) return 5;
    return 6;
}

int n;
vector<int> n_solved(5);
vector<char> a_solved(5), b_solved(5);
vector<int> a_t(5), b_t(5);
vector<int> var(5);

bool canGetUnsolved(int add_guys)
{
    for (int i = 0; i < 5; i++)
    {   
        if (a_solved[i]) continue;
            
        int mult = score_mult(n_solved[i], n + add_guys) - 1;
        if (mult > var[i])
            return false;
    }
    
    return true;
}

// type = 0: get lower bound, false if need increase
bool canGet(int add_guys)
{
    for (int i = 0; i < 5; i++)
    {
        if (!a_solved[i]) continue;
        int mult = score_mult(n_solved[i], n + add_guys) - 1;
        if (mult == var[i]) continue;
        
        if (mult < var[i])
            // need more guys to increase cost
            return false;
        
        // cost is more than needed, we need to solve this task
        
        int N = n + add_guys;
        
        int need_solved = 0;
        if (var[i] == 0) need_solved = N / 2 + 1;
        else if (var[i] == 1) need_solved = N / 4 + 1;
        else if (var[i] == 2) need_solved = N / 8 + 1;
        else if (var[i] == 3) need_solved = N / 16 + 1;
        else if (var[i] == 4) need_solved = N / 32 + 1;
        else
            need_solved = 0;
        
        //printf("task %d: need solved %d vs cur %d of %d\n", i, need_solved, n_solved[i], N);
        assert(n_solved[i] <= need_solved);
        if (need_solved - n_solved[i] > add_guys)
        {
            // not enough
            return false;
        }
    }
    
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int a;
            cin >> a;
            
            if (a != -1)
            {
                n_solved[j]++;
                
                if (i == 0)
                {
                    a_solved[j] = true;
                    a_t[j] = a;
                }
                
                if (i == 1)
                {
                    b_solved[j] = true;
                    b_t[j] = a;
                }
            }
        }
    }
    
    int minNeed = -1;
    
    for (int variant = 0; variant < 6 * 6 * 6 * 6 * 6; variant++)
    {
        //if (variant != 7) continue;
        
        int x = variant;
        
        int taskDelta = 0;
        
        for (int i = 0; i < 5; i++)
        {
            var[i] = x % 6;
            x /= 6;
            //printf("var %d, %d %d\n", var[i], a_solved[i], b_solved[i]);
            
            if (a_solved[i])
                taskDelta += (var[i] + 1) * 500 * (250 - a_t[i]);
            
            if (b_solved[i])
                taskDelta -= (var[i] + 1) * 500 * (250 - b_t[i]);
        }
        
#if 0
        bool my_var = (var[0] == 0 && var[1] == 2 && var[2] == 1 && var[3] == 2 && var[4] == 5);
        if (my_var)
        {
            printf("can %d\n", taskDelta);
            printf("your var\n");
            for (int i = 0; i < 5; i++)
                printf("var %d, base %d\n", var[i], score_mult(n_solved[i], n + 0) - 1);
            //canGet(1e9 + 7);
            //break;
        }
#endif
        
        if (taskDelta <= 0) continue;
        
        // get upper bound
        int UP = -1, DOWN = -1;
        {
            if (!canGetUnsolved(0)) continue;
                
            int low = 0, high = 1e9 + 8;
            while (low + 1 != high)
            {
                int m = (low + high) / 2;
                
                if (canGetUnsolved(m))
                    low = m;
                else
                    high = m;
            }
            
            UP = low;
        }
        
        {
            if (!canGet(UP)) continue;
            
            int low = -1, high = UP + 1;
            while (low + 1 != high)
            {
                int m = (low + high) / 2;
                
                if (canGet(m))
                    high = m;
                else
                    low = m;
            }
            
            DOWN = high;
        }
        
        //printf("UP %d DOWN %d\n", UP, DOWN);
        
        assert(DOWN <= UP && DOWN >= 0);
        
        if (minNeed == -1 || minNeed > DOWN)
            minNeed = DOWN;
        
        /*
        // 
        int low1 = -1, high1 = 1e9 + 8;
        if (!canGet(1e9 + 7, 0)) continue;
        while (low1 + 1 != high1)
        {
            int m = (low1 + high1) / 2;
            
            if (!canGet(m, 0))
                // too many
                high1 = m;
            else
                low1 = m;
        }
        // low1 is lower bound
        if (my_var)
            printf("lower bound %d\n", low1);
        
        int low2 = -1, high2 = 1e9 + 8;
        if (!canGet(0, 0)) continue;
        while (low2 + 1 != high2)
        {
            int m = (low2 + high2) / 2;
            
            if (!canGet(m, 0))
                // too few
                low2 = m;
            else
                high2 = m;
        }
        // low1 is lower bound
        
        //if (high2 >= low1)
        {
            int can = low1;
            assert(canGet(can, 0) && canGet(can, 1));
            
            if (minNeed == -1 || minNeed > can)
            {
                minNeed = can;
                //if (high == 1)
                //{
                //    exit(0);
                //}
            }
        }*/
        
        
        /*
        if (canGet(low, 0) && canGet(low, 1))
        {   
            minNeed = 0;
            break;
        }
        
        int low = 0, high = 1e9 + 7;
        if (!canGet(high)) continue;
        if (canGet(low))
        {
            minNeed = 0;
            break;
        }
        
        while (low + 1 != high)
        {
            int m = (low + high) / 2;
            
            if (canGet(m))
                high = m;
            else
                low = m;
        }
        
        for (int i = 0; i < 5; i++)
             printf("var %d, base %d\n", var[i], score_mult(n_solved[i], n + high) - 1);
        canGet(high);*/
    }
    
    cout << minNeed << endl;
    
    return 0;
}