n = gets.chomp.to_i
a = gets.chomp.split.map(&:to_i)
ans = Array.new(2, 0)
l, r, turn = 0, n - 1, 0
while l <= r do
  if a[l] > a[r]
    ans[turn] += a[l]
    l += 1
  else
    ans[turn] += a[r]
    r -= 1
  end
  turn = 1 - turn
end
puts [ans[0], ans[1]].join(' ')