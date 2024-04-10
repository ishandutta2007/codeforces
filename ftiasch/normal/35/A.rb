File.open('input.txt') do |f|
  now = f.gets.to_i
  3.times do 
    a, b = f.gets.split.map(&:to_i)
    if [a, b].index(now)
      now ^= a ^ b
    end
  end
  File.open('output.txt', 'w') { |f| f.puts now }
end