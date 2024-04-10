#!/usr/bin/ruby

require 'set'

n, m = gets.chomp.split.map(&:to_i)
col = Array.new(n+1){ |i| 0 }
row = Array.new(n+1){ |i| 0 }
scol = Set.new
srow = Set.new
res = n * n
ans = []
for i in 0...m do
  x, y = gets.chomp.split.map(&:to_i)
  unless col[x] == 1 && row[y] == 1
    csz = scol.size
    rsz = srow.size
    cmr = n - 1 - csz + col[x]
    rmr = n - 1 - rsz + row[y]
    if col[x] == 1
      res -= cmr
    elsif row[y] == 1
      res -= rmr
    else
      res -= rmr + cmr + 1
    end
  end
  col[x] = row[y] = 1
  scol << x
  srow << y
  ans.push( res )
end
puts ans.join(" ")