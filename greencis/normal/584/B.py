n = int(input())
mod = 1000000007
print(((27**n%mod - 7**n%mod) % mod + mod) % mod)