n, h = gets.chomp.split.map(&:to_i)
a = gets.chomp.split.map(&:to_i)
mod = 1000000007
dp = Array.new(n,0)
dp[0]=1
for i in 0...n do
  tdp = Array.new(n,0)
  nd = h-a[i]
  tdp[nd] = ( tdp[nd] + dp[nd] ) % mod if nd >= 0 && nd < n
  tdp[nd-1] = ( tdp[nd-1] + dp[nd] * nd ) % mod if nd-1 >= 0 && nd < n
  tdp[nd] = ( tdp[nd] + dp[nd-1] ) % mod if nd-1 >= 0 && nd < n
  tdp[nd-1] = ( tdp[nd-1] + dp[nd-1] ) % mod if nd-1 >= 0
  tdp[nd-1] = ( tdp[nd-1] + dp[nd-1] * (nd-1) ) % mod if nd-1 >= 0 && nd < n
  dp = tdp
end
puts dp[0]